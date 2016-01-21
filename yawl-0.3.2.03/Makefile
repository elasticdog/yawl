#  Makefile for "yawl"
#  Builds anagramming utilities,
#+ installs binaries, word list, man pages.

# Author: Mendel Cooper <thegrendel@theriver.com>
# License: Public Domain


all: anagram multi b_msg
install: install_list install_bins install_man i_msg

#  In the event you don't have a Pentium Pro (x586) or better machine,
#+ remove '-mcpu=pentiumpro' below.

anagram: anagram.c srch.h
	gcc -O3 -fomit-frame-pointer -v -Wall -mcpu=pentiumpro -o anagram anagram.c
	strip anagram

multi: multi.c srch.h
	gcc -O3 -fomit-frame-pointer -v -Wall -mcpu=pentiumpro -o multi multi.c
	strip multi

b_msg:
	@echo
	@echo "Binaries built."
	@echo "Now, \"make install\" as root."
	@echo


# As root, of course.

install_list:
	chmod 644 word.list
	cp word.list /usr/share/dict
	ln -s /usr/share/dict/word.list /usr/share/dict/word.lst
	@echo "word.list installed in /usr/share/dict and symlinked to word.lst."

install_bins:
	chmod 755 anagram multi wstrings.sh
	cp anagram multi wstrings.sh /usr/local/bin

install_man:
	chmod 644 anagram.1 multi.1
	cp anagram.1 multi.1 /usr/local/man/man1

i_msg:
	@echo
	@echo "============================================================="
	@echo "The word list (word.list) is now in /usr/share/dict."
	@echo "The \"anagram\" and \"multi\" binaries are in /usr/local/bin."
	@echo "The \"wstrings.sh\" executable script is in /usr/local/bin."
	@echo "Read README and the man pages for anagram and multi."
	@echo "Installation complete."
	@echo "============================================================="
	@echo
