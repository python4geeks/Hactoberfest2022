"""
List in File.
=============

Common functions for lists and objects in files.

"""


import pickle
from pathlib import Path


def save_list_to_file(in_list, out_f, encoding='utf-8'):
    """
    Saves a list of lines to a file.

    :param in_list: list of lines
    :param out_f: file name
    :param encoding: file encoding, default: 'utf-8'
    """

    Path(out_f).parent.mkdir(parents=True, exist_ok=True)
    with open(Path(out_f), 'w', encoding=encoding) as f_out:
        for line in in_list:
            f_out.write(str(line) + '\n')


def get_list_from_file(in_f, encoding='utf-8'):
    """
    Returns a list of lines from a file.

    :param in_f: file name
    :param encoding: file encoding, default: 'utf-8'
    :return: list of lines from a file
    """

    with open(Path(in_f), encoding=encoding) as f_in:
        for line in f_in:
            yield line.rstrip()


def save_obj_to_file(in_obj, out_f):
    """
    Saves (serializes) the object to a file.

    :param in_obj: object, or list of objects
    :param out_f: file name
    """

    Path(out_f).parent.mkdir(parents=True, exist_ok=True)
    with open(out_f, 'wb') as f_out:
        pickle.dump(in_obj, f_out)


def get_obj_from_file(in_f):
    """
    Returns (deserializes) an object from a file.

    :param in_f: file name
    :return: object from a file
    """

    with open(Path(in_f), 'rb') as f_in:
        return pickle.load(f_in)
