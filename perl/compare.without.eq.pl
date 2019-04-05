#!/usr/bin/perl -w

print "Enter Number:";
$n1=<>;

print "Enter Next Number:";
$n2=<>;

chomp($n1);
chomp($n2);

if($n1-$n2)
{
  print "$n1 and $n2 are NOT Equal!\n";
}
else
{
  print "$n1 is same as $n2!\n";
}
exit 0;
