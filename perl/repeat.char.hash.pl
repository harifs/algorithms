#!/usr/bin/perl

### ENTER a STRING, may be a paragraph... and find the FIRST character, that doesn't repeat in Entire String.

print "Enter the String:";
$str=<>;
chomp($str);
@chars=split(//,$str);  # Converting String to Char Buffer

%charHash=();

##### Loading the character buffer into HASHMAP, the character is the key, number of occurances is the value
for($i=0;$i<@chars;$i++)
{
  $charHash{$chars[$i]} = ($charHash{$chars[$i]}+1);
}

  ##### 1. Print the HASH TABLE - Practice - not mandatory in this program
  print "PRINT HASH as it is!\n";
  while (($key,$value)=each(%charHash))
  {
   print "$key=>$value\n";
  } 
  
  ##### 2. SORT the HASH by Key - Practice - not mandatory in this program
  print "SORT HASH by KEY!\n";
  foreach $k (sort keys %charHash)
  {
   print "$k=>$charHash{$k}\n";
  } 
  
  ##### 3. SORT the HASH by Value (sort funtction in perl offers a lot) - Practice - not mandatory in this program
  print "SORT HASH by VALUE!\n";
  foreach $k (sort {$charHash{$a} cmp $charHash{$b}} keys %charHash)
  {
   print "$k=>$charHash{$k}\n";
  } 
  
##### Actual Function, identifying the first non-repeating character
print "\nFinding the First Non-repeating Character in the Entered String!\n";
for($i=0;$i<@chars;$i++)
{
  if($charHash{$chars[$i]} eq 1)
  {
   print "$chars[$i] is the first NON-repeating Character\n";
   exit 0;
  }
}
print "All the Characters in the string are Repeating!\n";
exit 1;
