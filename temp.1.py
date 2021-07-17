import urllib.request
import urllib.parse
import urllib.error
from bs4 import BeautifulSoup
import os

url = "https://github.com/ryanoasis/nerd-fonts/releases/tag/v2.1.0"
html = urllib.request.urlopen(url).read()
soup = BeautifulSoup(html, 'html.parser')

# Retrieve all of the anchor tags
lst = list()
tags = soup('a')
for tag in tags:
    temp = tag.get('href', None)
    if temp.startswith("/ryanoasis/nerd-fonts/releases/download/v2.1.0/"):
        lst.append("https://github.com" + temp)
for i in lst:
    os.system("wget "+i)
