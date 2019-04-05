#\home\user\local\bin\perl -w

use strict;
my @deck=0;
my @cardface=0;
my @cardsuit=0;
my $n=0;
my $i=0;
my $j=0;
my $cnt=0;
my $p=0;
my $q=0;
my $nelem=0;
my $nhalf=0;
my $nparts=0;
my $temp=0;

@cardface=('A','2','3','4','5','6','7','8','9','10','J','Q','K');
@cardsuit=('s','h','d','c');

print "\ncardsuit=@cardsuit";
foreach $i (@cardface)
{
 foreach $j (@cardsuit)
 {
 	print "\n n=$n; i=$i;j=$j";
	$deck[$n++]="$i$j";	
 }
}

print "\n";

for($i=0;$i<$n;$i++)
{
	print "$deck[$i]\t";
}

shuffle(@deck);
print "\n\n After shuffling... \n";

for($i=0;$i<$n;$i++)
{
	print "$deck[$i]\t";
}

#################
### FUNCTIONS ###
#################
sub shuffle(@deck)
{
	print "shuffling..";	
	for($cnt=0;$cnt<2;$cnt++)
	{
		print "\n cnt=$cnt";
		splitmerge(@deck);
	}
#	for($i=0;$i<5;$i++)
#	{
#		cutstack($i+2);
#	}
}

sub splitmerge(@deck)
{
 	print "split...and..merge the deck..";
 	$nelem=@deck;
	$nhalf=$nelem/2;
	print "\nelem=$nelem; nhalf=$nhalf";
	for ($i=0,$j=$nhalf;$i<$nhalf;$i++,$j++)
	{
		print "\n Swapping $deck[$i] and $deck[$j]..";
		swap(@deck,$i,$j);
	}
	return (0);
}

sub cutstack(@deck,$nparts)
{
	print "cut to $nparts..and..merging the deck..";
}

sub swap(@deck,$p,$q)
{	
	$temp=$deck[$p];
	$deck[$p]=$deck[$q];
	$deck[$q]=$temp;
}