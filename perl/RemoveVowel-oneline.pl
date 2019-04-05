#!/usr/bin/perl

#### Remove a,e,i,o,u from the String!

print "Enter a String:";
$str=<>;
chomp($str);

$str =~ s/[aeiou]//g;

print "Vowel removed string: $str\n";
