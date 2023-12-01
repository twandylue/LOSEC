# LOSEC

This project is the final project of CSCI200 at Mines.

## How to Start

Input your query, LOSEC would help you to find out related documents containing your query words under `./data/` folder.

```console
$ make && ./losec
Please input your query: test2
Indexing...
File name: "./data/test2.txt"
File name: "./data/test3.txt"
File name: "./data/test.txt"
Indexing completed!

Searching...
Results(file path/score):
./data/test2.txt: 0.0293485
./data/test.txt: 0
./data/test3.txt: 0
```

## TODO

- [ ] Unit test Framework
