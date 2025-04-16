#!/usr/bin/node

const request = require("request");

const movieId = process.argv[2];

if (!movieId) {
  console.log("Usage: ./0-starwars_characters.js <Movie ID>");
  process.exit(1);
}

const filmUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

// Requête pour obtenir les données du film
request(filmUrl, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  if (response.statusCode !== 200) {
    console.error(`Erreur ${response.statusCode}`);
    return;
  }

  const filmData = JSON.parse(body);
  const charactersUrls = filmData.characters;
  const characters = [];
  let count = 0;

  // Pour chaque URL de personnage
  charactersUrls.forEach((url, index) => {
    request(url, (err, res, body) => {
      if (err) {
        console.error(err);
        return;
      }

      if (res.statusCode !== 200) {
        console.error(`Erreur ${res.statusCode} pour ${url}`);
        return;
      }

      const characterData = JSON.parse(body);
      characters[index] = characterData.name;
      count++;

      // Quand toutes les requêtes sont terminées
      if (count === charactersUrls.length) {
        characters.forEach((name) => console.log(name));
      }
    });
  });
});
