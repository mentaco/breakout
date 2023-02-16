# -c オプションでオブジェクトファイルを作ってから
#  実行ファイルを作ると何故かエラーが出るため、
#  コンパイルとリンクを同時にする。

CC = g++
LIBS = -lncurses
FILES = main.cpp paddle.cpp

all: $(FILES)
	$(CC) $(FILES) $(LIBS)
