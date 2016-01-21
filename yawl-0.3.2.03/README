                      Yet Another Word List [YAWL]

                                    i
                                 The List

Why indeed is there even a need for Yet Another Word List? The notorious
"linux.words" list, the public domain "Websters 2", the ispell and
cracklib dictionaries, not to mention various and sundry purported
Scrabble lists are already available in electronic form. None of these,
though, are optimized for word game use and as comprehensive as the
YAWL. At 264,097 words, this list supersedes the SOWPODS list beloved of
international Scrabble players. There is no arbitrary word length cutoff,
and even words longer than 20 letters find a place in the list.

Care has been taken to ensure that the YAWL word list (word.list) will
for all time remain copyright free. It is based on the updated Public
Domain ENABLE (Enhanced North American Benchmark Lexicon), researched and
compiled by the author and his colleague, Alan Beale. The ENABLE list
has become a sort of de facto on-line standard for word gaming, having
been adopted by  Scrabble servers and used as the basis for at least
one commercial word game. Additional content in the list came from Alan
Beale's painstakingly researched "2DICTS," "12DICTS," "OSPDADD" lists, an
"OSW" clone list generously contributed by the amateur lexicographer,
C.M.L. Wristlock, David Duffy's list of Australian bird names, and
a short list of computer and other jargon-oriented "signature words"
added by the author of this package. While there might be suspicions of
arbitrariness in the choice of words these signature words, they add a
pungent, slightly smoky idiosyncratic flavor to the brew.

Those who, in spite of themselves,  develop an asthetic appreciation of
the YAWL package are urged to download the lists it is based on, in the
ENABLE2K and SUPP2K archives, from
http://personal.riverusers.com/~thegrendel/software.html.
These archives contain Alan Beale's erudite, but eminently readable
research notes, a treat for the amateur lexicographer.

The YAWL word list itself (word.list) is, of course, in standard
UNIX ASCII format, one word per line, terminated by an LF. Those
unfortunate Windows persons desiring a DOS ASCII word file, lines
terminated by an LF-CR, can download the "tofrodos" package from
http://chrisheng.hypermart.net/ or http://thor.prohosting.com/~cslheng/,
which contains both 16 and 32-bit Windows executables for converting
text files from UNIX to DOS format.

The "md5sum" of the word list file, word.list, is:
              4b9dc4abfe87e6a028c598ad7c5638f4
You can check its integrity by running 'md5sum' on it, to ensure that it
hasn't been altered.


The YAWL list, word.list, is herewith and forever placed in the
Public Domain, which means there are no restrictions on its use and
redistribution for "lawful" purposes. This means you may not use the list
to rob banks or swindle investors, but short of that, pretty much anything
goes. If you decide to incorporate the list into a game, application,
or product, the author requests, as a courtesy, notification of same,
so that he can gain a moment's satisfaction in return for all the effort
he has put into this project.



                                       ii
                           The "Signature" Word List

The 261 entries in the signature word list are not commonly accepted words.
They come from various expert and insider jargons, as well as from recent
usage.

Certain of these words, such as "soulmate" and "blog" will sooner or
later make it into the mainstream language. Others, such as "bogomip,"
probably will not. A very few have been specially created by the author
of this list. Let us examine one of these entries.

darl [v.t.]
     [Short "a" -- pronounced as in "derelict."]
     To steal or expropriate community property for one's personal use.

     As an example of property that has been "darled," consider New York
     City's experience with the metal mesh waste cans that were placed on
     street corners some years back. Many of these cans ended up in suburban
     backyards, serving as barbecue pits and receptacles to burn leaves in.
     Quite a few commuters into the city apparently darled these cans.

     Jack had a nice wrough iron and wood bench on his porch. When he
     had a few beers in him, he might confess that he had darled it from
     the nearby city park. He might further admit that darling was not
     an ethical activity, but hey, he needed a place to sit down while
     drinking his beer.





                                      iii
                             The Utilities

This version of the YAWL package includes two simple anagramming
utilities. They are interesting and useful in their own right, but
their true purpose is to inspire all the Linux word gamers and coders
out there to invent and create...  word games, using the YAWL list,
of course.  It would truly be nice to see a successor to Scrabble -
a new generation word game with strategic depth, a word game with some
of the sheer crystalline beauty of chess and the sheer profundity of Go,
a word game rewarding artistic play rather than dry list memorization,
a word game for those who truly love the richness of the English language
and revel in its peculiar permutations, a word game that will take the
gaming community by storm, a word game that will invade living rooms
all across the civilized world, in short, a word game fated to run on
millions of Linux machines.


Using 'anagram' involves nothing more than typing, from the command line
(console or xterm), 'anagram letter-set [dictionary]'. Omitting the
[dictionary] defaults to the YAWL list, installed by this package as
"word.list" in /usr/dict.  Omitting the letter set causes the program
to prompt the user for input.  The letter set may include "wild cards"
(blank tiles), which are represented as underscores (_). The output goes
to stdout, and may, of course be redirected to a file.

Examples:
  anagram lkwa
  ------------
     al
     aw
     awl
     ka
     la
     law
     walk
 
   anagram whea_l
   --------------
     aa
     aah
     aal
     ab
     able
     ace
     ache
     ... and 459 other words.

   anagram abcd /usr/dict/linux.words
   ----------------------------------
     anagrams the letterset "abcd" using /usr/dict/linux.words.



The multiple word anagram utility, "multi" works similarly. The syntax, from
the command line, is:
   multi [letter set] [number of words] [word file]

Example:
   multi abcdefghij 3
   ------------------
   bach fed jig
   bach jig fed
   bad chef jig
   ...
   bid chef jag
   ...
   jab chef dig
   ...and 49 other combinations.

Using "multi" can provide some cheap thrills when a party gets dull.

Both "anagram" and "multi" have their own man pages, installed by a
"make install".

It would take only a few small tweaks (hint: pipe to 'grep') to transform
the anagram code into an unscramble tool for "scramblegrams" or even a
"find the missing letters" utility for crossword puzzle fans. This is
left as an "exercise for the reader".




                                       iv
                            The "wstrings.sh" Script

This shell script is an enhanced version of the built-in "strings" command. It
filters the output of "strings" to show only "legal" words.

If you don't know what this is all about, try 'man strings' to find out.



                                       v
                                    Checksum

As of this version of yawl, the md5 checksum of the word.list file is
      4b9dc4abfe87e6a028c598ad7c5638f4


                                       vi
                         Perquackey & Other Word Games

The yawl list is the recommended word list package for the author's Quackey
anagramming word game (a software clone of Perquackey). See:
   http://personal.riverusers.com/~thegrendel/qky.README.html

Quite a number of on-line word gaming sites likewise use the yawl list.
You are encouraged to use the yawl package for any word games you write.




Note: The author of this software will provide no support for Unixware (c) or
      any other SCO products. Likewise MS Windows. Don't even ask.


Mendel Cooper
thegrendel@theriver.com

--
Scrabble is a registered trademark of Milton Bradley, a subsidiary of Hasbro,
Inc.

Unixware is a registered trademark of The Open Group.

ENABLE, YAWL, and 2DICTS are not trademarks.
