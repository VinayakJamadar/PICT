import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin

start_url = "https://en.wikipedia.org"
domain = "en.wikipedia.org"  # Target domain

visited_urls = set()
to_crawl = [start_url]
max_pages = 10
user_agent = "Your User Agent Here"

while to_crawl and len(visited_urls) < max_pages:
    url = to_crawl.pop(0)
    if domain not in url:
        continue
    headers = {"User-Agent": user_agent}
    response = requests.get(url, headers=headers)
    if response.status_code == 200:
        soup = BeautifulSoup(response.text, 'html.parser')
        visited_urls.add(url)
        for link in soup.find_all('a', href=True):
            new_url = urljoin(url, link['href'])
            if new_url not in visited_urls and new_url not in to_crawl:
                to_crawl.append(new_url)

print("Visited URLs:")
for url in visited_urls:
    print(url)

