#! /usr/bin/perl

######
### Write a function that, given a stream of lines of text, prints all lines (in order) except those that have already been printed (remove duplicates).
######

######
### HASH to store the printed elements as Keys
######
%printed;

######
### External File -> source of data
######
open(INPUT_FILE, "<$ARGV[0]") || die "Cannot open input file $ARGV[0]. Cause: <$!>\n";

######
### Till end of file, for each line;
######
while($line = <INPUT_FILE>)
{
  chomp($line);
  $already_printed_flag=0;
  
  ######
  ### IF HASH of Printed lines is not empty, if the current line is present in the HASH, it was printed before, so dont print it, go to next line.
  ######
  unless(%$printed)
  {
   if($printed{$line})
   {
      $already_printed_flag=1;
      $printed{$line} = ($printed{$line}+1); ### It keeps the count of the repetition of the same line, in the value, can be used for accounting.
      break;
   }
  }

 ######
 ### If the flag is still zero, after browsing through the complete HASH, it is a brand new line, print it and add it to HASH
 ######
 if($already_printed_flag eq 0)
 {
  print "$line\n";
  $printed{$line} = 1;
 }
}
