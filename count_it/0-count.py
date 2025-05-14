#!/usr/bin/python3
"""Module pour compter récursivement les occurrences de mots-clés dans les
titres des articles chauds d'un subreddit."""
import requests


def count_words(subreddit, word_list, after=None, counts={}):
    """Compte les mots-clés présents dans les titres des articles
        chauds d'un subreddit.

    Args:
        subreddit (str): Nom du subreddit à interroger.
        word_list (list): Liste des mots-clés à rechercher.
        after (str): Paramètre de pagination pour l'API Reddit.
        counts (dict): Dictionnaire stockant le nombre d'occurrences.

    Affiche :
        Le comptage trié des mots-clés selon leur fréquence,
                en ordre décroissant.
    """
    headers = {'User-Agent': 'Python3/requests'}
    params = {'after': after} if after else {}
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'

    response = requests.get(url, headers=headers, params=params,
                            allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json().get('data', {})
    posts = data.get('children', [])

    if not posts:
        return

    for post in posts:
        title = post.get('data', {}).get('title', '').lower().split()
        for word in word_list:
            word_lower = word.lower()
            counts[word_lower] = counts.get(
                word_lower, 0) + title.count(word_lower)

    after = data.get('after')
    if after:
        count_words(subreddit, word_list, after, counts)
    else:
        sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
        for word, count in sorted_counts:
            if count > 0:
                print(f"{word}: {count}")
