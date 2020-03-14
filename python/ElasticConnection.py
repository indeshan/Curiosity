#import Elasticsearch package 
from elasticsearch import Elasticsearch
import sys 
# Connect to the elastic cluster
#es=Elasticsearch([{'host':'localhost','port':9200}])

es = Elasticsearch(
    ['localhost'],
    http_auth=('elastic', 'changeme'),
    port=9200,
)

res=es.search(index='shakespeare',body={'query':{'match':{'text_entry':'the'}}})

for value in res['hits']['hits']:
    print (value)
