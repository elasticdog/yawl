Yet Another Word List (YAWL)
============================

by Mendel Leo Cooper (a.k.a. thegrendel);
originally hosted at http://freshmeat.net/projects/yawl/

Forward
-------

> I have a personal interest in developing word games, and finding curated word
> lists is no easy task. Many word lists exist, but are proprietary or have
> unfriendly licenses for developers to use in their own projects. Luckily,
> some people (not me) have worked incredibly hard to create extensive word
> lists and release them into the public domain.
>
> One such word list is M. Leo Cooper's "Yet Another Word List" (YAWL), which
> has unfortunately started to disappear from the Internet. Digging through
> Google results and the Internet Archive yields a few places where his work is
> preserved, but mostly older versions of YAWL. After a lot of searching,
> I eventually found what I believe is the most recent version of the word
> list, and have decided to rehost that here.
>
> This repository is my attempt to prevent YAWL from being lost to time so that
> other developers can benefit from M. Leo Cooper's work.
>
> --- _Aaron Bull Schaefer (a.k.a. elasticdog)_

About
-----

This is a comprehensive "word game" word list for UNIX/Linux. It is a superset
of the author's ENABLE list, the "OSW", and various lists researched by the
author's colleague, Alan Beale. At 264,097 words, it is the largest list of its
kind, suitable for use in all manners of crossword-type board games and word
construction games, as well as for a spell checker dictionary. The YAWL package
now includes two anagramming utilities (supplied as source code, handled by the
included Makefile). There is also a shell script that extends the UNIX
"strings" system command.

Release Notes
-------------

### 0.3.2.03 - 2008-06-20

- New entries in word.list.

### 0.3.2.02 - 2008-05-12

This release adds a couple dozen topical words to the main list, such as
blog, botnet, etc.

- New entries in word.list.
- Minor changes to man pages.

### 0.3.2 - 2004-10-06

Another set of bugfixes. The "install" part of the Makefile now works. The
manpages updated.  Everything should be all right now [grin].

- Had to fix Makefile to instill in correct dictionary directory (double-duhh!).

### 0.3.1 - 2005-10-05

This release adds a minor update to the signature word list and the master word
list, updates the Makefile, and fixes anagram.c and multi.c to keep an error in
the string giving the author's name from crashing the build.

- Minor update to signature word list, and to master word list.
- Updated Makefile.
- Fixed anagram.c and multi.c to keep a stupid error in string giving author's
  name from crashing the build (duhhh!).

### 0.2.01 (same as 0.3) - 2003-06-24

This release adds a minor update to the signature word list and the master word
list, updates the Makefile, and fixes anagram.c and multi.c to keep an error in
the string giving the author's name from crashing the build.

- Updated master word list.
- Updated Makefile.
- Added "wstrings.sh" shell script to package.

### 0.2 - 2000-04-28

- The master word list, "word.list", completely rebuilt to track changes in the
  updated millennial release of "ENABLE2K" list.
- Source code for anagramming and multiple-word anagramming utilities added to
  package.
- README file revised and updated.

### 0.1 - 1999-07-04

- First release.

License
-------

The YAWL list, word.list, is in the Public Domain. There are no restrictions on
its use or distribution.

The author decided to release the list into the Public Domain because it is
based primarily on other Public Domain lists by the author and his colleague,
Alan Beale, and applying the stricter GPL to it would therefore be of doubtful
validity.

The author has also released the source code to "anagram" and "multi" (multiple
word anagram) into the Public Domain. He had previously posted these utilities
on the "alt.sources" newsgroup in shar archive form.

The author has released his "wstrings.sh" script into the Public Domain. It is
part of his ["Advanced Bash Scripting Guide"](http://www.tldp.org/LDP/abs/html/)
which is hosted on the [Linux Documentation Project](http://www.tldp.org).

Please feel free to use the word list and/or source code in your own projects.
It is, in fact, the intent of the author that this package inspire word game
software for the Linux platform. If you use any portion of YAWL, please, as
a courtesy, give credit to its author.

Note that "Public Domain" *means* Public Domain. Even if portions or the whole
of this package are incorporated into a commercial or proprietary application,
those portions of YAWL within it *remain* Public Domain.
