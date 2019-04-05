#!\user\local\bin\perl -w
use strict;

my ($prevprev,$prev,$current,$n,$i);
print "\nEnter the Number:";
$n=<>;
chomp($n);
$prevprev=1;
$prev=1;

if($n<1) 
{
	print "Invalid input";
	exit 1;
}
if ($n<3)
{
	print "\n${n}th fibonacci number is 1\n";
	exit 0;
}

for($i=3;$i<=$n;$i++)
{   
	$current=$prev+$prevprev;
	$prev=$current;
	$prevprev=$prev;
}
print "\n${n}th fibonacci number is $current\n";

exit 0;