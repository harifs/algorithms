#!\user\local\bin\perl -w
use strict;

my ($i,$n,$fib);
print "\nEnter the Number:";
$n=<>;
chomp($n);
$fib=&fibo($n);

print "\n${n}th fibonacci number is $fib\n";

sub fibo()
{
	my $n = shift;
	my $fsum=0;
	if($n<1)
	{
		return 0;
	}
	elsif($n>2)
	{
		$fsum = $fsum+&fibo($n-1)+&fibo($n-2);
		return $fsum;
	}
	else
	{
		return 1;
	}
}
