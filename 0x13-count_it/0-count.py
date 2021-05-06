#!/usr/bin/python3
"""
0. Count it!
"""
import requests


def count_words(subreddit, word_list):
    """ function that queries the Reddit API,
    parses the title of all hot articles,
    and prints a sorted count of given keywords"""
    word_list = [str.lower() for str in word_list]

    my_list = get_hot_list(subreddit)
    my_dict = {}

    for word in word_list:
        my_dict[word] = 0

    for title in my_list:
        title_split = title.split(" ")

        for iter in title_split:
            for iter_split in word_list:
                if iter.lower() == iter_split.lower():
                    my_dict[iter_split] += 1

    for key, val in sorted(my_dict.items(), key=lambda x: x[1],
                           reverse=True):
        if val != 0:
            print("{}: {}".format(key, val))


def get_hot_list(subreddit, hot_list=[], after=None):
    """function that return hot list from a subreddit"""
    headers = {'User-agent': 'Chrome'}
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)

    parameters = {'after': after}
    res = requests.get(url, headers=headers, allow_redirects=False,
                       params=parameters)
    if res.status_code == 200:
        prox = res.json().get('data').get('after')
        if prox is not None:
            get_hot_list(subreddit, hot_list, prox)
    else:
        return (None)
    try:
        dic_json = res.json()
        for title_ in dic_json['data']['children']:
            hot_list.append(title_['data']['title'])
        return hot_list
    except Exception:
        return None
