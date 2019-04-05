#!/usr/bin/perl

#### Reverse the WORDS (without affecting the sanity of the each word)

print "Enter a String:";
$str=<>;
chomp($str);

$revStr=join(" ",reverse(split(/ /,$str)));

print "Reversed Words: $revStr\n";
