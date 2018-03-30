import requests,sys,bs4,webbrowser

#Making request to the server
print('Search in Progress.....')
res = requests.get('https://www.google.co.in/search?dcr=0&ei=vpCSWoLyK8bTvwTxgIiYDg&q=' + ' '.join(sys.argv[1:]))
res.raise_for_status()

#Get search results
soup = bs4.BeautifulSoup(res.text,"lxml")
print(soup.prettify())

#opens a tab for each result
elems = soup.select('.r a')
nOpen = min(2,len(elems))
for i in range(nOpen):
    webbrowser.open('https://google.com' + elems[i].get('href'))
    



