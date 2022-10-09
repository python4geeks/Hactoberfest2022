"""
Download file.
============

"""

import logging
from pathlib import Path

import requests

USER_AGENT = ('Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 '
              '(KHTML, like Gecko) Chrome/67.0.3396.87 Safari/537.36')
HEADERS = {'User-Agent': USER_AGENT}


def download_file(url, f_name):
    """
    Download file

    :param url: file link
    :param f_name: file name
    """
    logging.basicConfig(level=logging.INFO)

    Path(f_name).parent.mkdir(parents=True, exist_ok=True)
    while True:
        try:
            logging.info(f'\nFile: {Path(f_name).name}\n')
            response = requests.get(url, headers=HEADERS)
            logging.info(f'\nDownload file:\n{url}\n{"=" * 30}\n')
            with open(Path(f_name), 'wb') as f_out:
                f_out.write(response.content)
            break
        except Exception as e:
            logging.warning(f'{e}')
