#!\user\local\bin\perl -w
use strict;

my ($i,@fn,$n);
print "\nEnter the Number:";
$n=<>;
chomp($n);
$fn[0]=1;
$fn[1]=1;

for($i=2;$i<$n;$i++)
{
    $fn[$i]=$fn[$i-1]+$fn[$i-2];
}
print "\n${n}th fibonacci number is $fn[$n-1]";