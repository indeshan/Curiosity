#!/bin/bash

#.log files delete > 30 days old
find /path/to/root/folder -type f -name '*.log' -mtime +30 -exec rm -f {} +

#.csv files delete > 60 min old
find /path/to/root/folder -type f -name '*.csv' -mmin +60 -exec rm -f {} +

#.pdf files delete > 60 min old
find /path/to/root/folder/ -type f -name '*.pdf' -mmin +60 -exec rm -f {} +

#.txt files delete > 24 h old
find /path/to/root/folder/ -type f -name '*.txt' -mmin +1440 -exec rm -f {} +
