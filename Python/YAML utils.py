"""
YAML utils.
=============

Common functions for YAML.

"""

import json
from pathlib import Path

from ruamel.yaml import YAML


def add_in_yaml(data, f_name, encoding='utf-8', flow_style=True):
    """
    Adds objects to YAML file.

    :param data: an object, or a list of objects to add
    :param f_name: YAML file name
    :param encoding: YAML file encoding, default: 'utf-8'
    :param flow_style: True or False
    """

    yaml = YAML(pure=True)
    yaml.default_flow_style = flow_style
    sep = ''
    if Path(f_name).exists():
        mode = 'a'
        if Path(f_name).stat().st_size:
            if isinstance(data, dict):
                sep = '---\n'
    else:
        mode = 'w'
    Path(f_name).parent.mkdir(parents=True, exist_ok=True)
    with open(Path(f_name), mode, encoding=encoding) as f:
        if sep:
            f.write(sep)
        yaml.dump(data, f)


def get_from_yaml(f_name, encoding='utf-8'):
    """
    Returns an object generator from a YAML file.

    :param f_name: YAML file name
    :param encoding: YAML file encoding, default='utf-8'
    :return: object generator
    """

    yaml = YAML(pure=True)
    with open(Path(f_name), encoding=encoding) as f:
        for item in yaml.load_all(f):
            yield item


def yaml_to_json(yaml_file, json_file,
                 yaml_encoding='utf-8', json_encoding='utf-8'):
    """
    Converts JSON file to YAML file.

    :param yaml_file: YAML file name
    :param json_file: JSON file name
    :param yaml_encoding: YAML file encoding, default='utf-8'
    :param json_encoding: JSON file encoding, default='utf-8'
    """
    yaml_list = list(get_from_yaml(yaml_file, encoding=yaml_encoding))
    indent = ' ' * 4
    with open(json_file, 'w', encoding=json_encoding) as f:
        json.dump(yaml_list, f, ensure_ascii=False, indent=indent)
