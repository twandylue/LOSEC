# LOSEC

This project is the final project of CSCI200 at Mines.

## How to Start

Input your query, LOSEC would help you to find out top 5 related documents under `./data/` folder according to your input query.

```console
$ make && ./losec
Welcome to Local Search Engine!
Please input your query: test2
Indexing files under ./data/ folder...
File name: "./data/test6.txt"
File name: "./data/test4.txt"
File name: "./data/test5.txt"
File name: "./data/test2.txt"
File name: "./data/test3.txt"
File name: "./data/test.txt"
Indexing completed!

Searching...
Top 5 Results(file_path/score):
./data/test2.txt: 0.0795202
./data/test.txt: 0
./data/test5.txt: 0
./data/test4.txt: 0
./data/test3.txt: 0
```

## TODO

- [ ] Unit test Framework
