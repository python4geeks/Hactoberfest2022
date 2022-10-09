"""
CSV utils.
==========

Common functions for lists and dictionaries in CSV files.

"""

import csv
from pathlib import Path

import numpy


def get_dicts_from_csv(f_name, encoding='utf-8', newline='', delimiter=','):
    """
    Returns a dictionary list generator from a CSV file.

    :param f_name: CSV file name
    :param encoding: CSV file encoding, default='utf-8'
    :param newline: default='', corrects '\r\r\n' -> '\r\n'
        https://docs.python.org/3/library/csv.html#id3
    :param delimiter: default=',', cell delimiter ',' or ';'
    :return: dictionary list generator from a CSV file
    """

    with open(Path(f_name), encoding=encoding, newline=newline) as f_in:
        csv_reader = csv.DictReader(f_in, delimiter=delimiter)
        for row in csv_reader:
            yield row


def save_dicts_to_csv(in_list, f_name, field_names,
                      encoding='utf-8', newline='', delimiter=','):
    """
    Saves a list of dictionaries to a CSV file.

    :param in_list: list of dictionaries
    :param f_name: CSV file name
    :param field_names: list of column headers in CSV file
    :param encoding: CSV file encoding, default='utf-8'
    :param newline: default='', corrects '\r\r\n' -> '\r\n'
        https://docs.python.org/3/library/csv.html#id3
    :param delimiter: default=',', cell delimiter ',' or ';'
    """

    Path(f_name).parent.mkdir(parents=True, exist_ok=True)
    with open(f_name, 'w', encoding=encoding, newline=newline) as f_out:
        csv_writer = csv.DictWriter(f_out, fieldnames=field_names,
                                    delimiter=delimiter)
        csv_writer.writeheader()
        csv_writer.writerows(in_list)


def get_lists_from_csv(f_name, encoding='utf-8', newline='', delimiter=','):
    """
    Returns a list of lists generator from a CSV file.
    The first list is the column headers of the CSV file.

    :param f_name: CSV file name
    :param encoding: CSV file encoding, default='utf-8'
    :param newline: default='', corrects '\r\r\n' -> '\r\n'
        https://docs.python.org/3/library/csv.html#id3
    :param delimiter: default=',', cell delimiter ',' or ';'
    :return: list of lists generator
    """

    with open(Path(f_name), encoding=encoding, newline=newline) as f_in:
        csv_reader = csv.reader(f_in, delimiter=delimiter)
        for row in csv_reader:
            yield row


def save_lists_to_csv(in_list, f_name, encoding='utf-8',
                      newline='', delimiter=','):
    """
    Saves the list of lists to a CSV file.
    The first list is the column headers of the CSV file.

    :param in_list: list of lists
    :param f_name: CSV file name
    :param encoding: CSV file encoding, default='utf-8'
    :param newline: default='', corrects '\r\r\n' -> '\r\n'
        https://docs.python.org/3/library/csv.html#id3
    :param delimiter: default=',', cell delimiter ',' or ';'
    """

    Path(f_name).parent.mkdir(parents=True, exist_ok=True)
    with open(Path(f_name), 'w', encoding=encoding, newline=newline) as f_out:
        csv_writer = csv.writer(f_out, delimiter=delimiter)
        csv_writer.writerows(in_list)


def get_fieldnames_from_csv(f_name, encoding='utf-8',
                            newline='', delimiter=','):
    """
    Returns a list of column headers in a CSV file.

    :param f_name: CSV file name
    :param encoding: CSV file encoding, default='utf-8'
    :param newline: default='', corrects '\r\r\n' -> '\r\n'
        https://docs.python.org/3/library/csv.html#id3
    :param delimiter: default=',', cell delimiter ',' or ';'
    :return: list of column headers
    """

    with open(Path(f_name), encoding=encoding, newline=newline) as f_in:
        return csv.DictReader(f_in, delimiter=delimiter).fieldnames


def save_csv_parts(f_name, num_parts, encoding='utf-8',
                   newline='', delimiter=','):
    """
    Splits a CSV file into roughly equal parts.

    :param f_name: CSV file name
    :param num_parts: number of parts
    :param encoding: CSV file encoding, default='utf-8'
    :param newline: default='', corrects '\r\r\n' -> '\r\n'
        https://docs.python.org/3/library/csv.html#id3
    :param delimiter: default=',', cell delimiter ',' or ';'
    """

    list_of_dicts = []
    with open(Path(f_name), encoding=encoding, newline=newline) as f_in:
        csv_reader = csv.DictReader(f_in, delimiter=delimiter)
        field_names = list(csv_reader.fieldnames)
        for row in csv_reader:
            list_of_dicts.append(row)

    parts = numpy.array_split(list_of_dicts, num_parts)
    for count, part in enumerate(parts, 1):
        save_dicts_to_csv(
            part,
            f'{Path(f_name).name}_{count:03}.csv',
            field_names
        )
