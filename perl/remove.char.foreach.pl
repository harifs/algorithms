#!/usr/bin/perl

#### Remove a,e,i,o,u from the String!

print "Enter a String:";
$str=<>;
chomp($str);

### further simplification is; $str =~ s/[aeiou]//g;
foreach $i(a,e,i,o,u)
{
  $str =~ s/$i//g;
}

print "Vowel removed string: $str\n";
