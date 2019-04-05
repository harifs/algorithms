#!\user\local\bin\perl -w
#use strict;

@A=(1,2,3,4,5,6);
@B=reverse sort {$a<=>$b} @A;

print "\nOrginal Array = @B";
$B=@B;
$count=0;
print "\nEnter the sum:";
$sum=<>;
chomp($sum);
my @c=();
my %sumhash;
# IGNORE all elements greater than the SUM
for ($i=0;$i<$B;$i++)
{
	if($B[$i] == $sum)
	{
		$count++;
		push(@c,$B[$i]);
	}	
	elsif( $B[$i] < $sum)
	{
		push(@c,$B[$i]);
	}
}
print "\nSorted Array = @c\n count=$count";

# Fixing the start and floating the end
$k=@c;

while($k>=0)
{
$j=$k-1;
$i=0;
$tmpsum=$c[$i];
while($i<$j)
{
	$tmpsum+=$c[$j];
print "\nk=$k,i=$i,j=$j,c[i]=$c[$i],c[j]=$c[$j],tmpsum=$tmpsum,count=$count";
	if($tmpsum == $sum)
	{		
		$tmpvar=$c[$i];
		for($tc=$j;$tc<$k;$tc++)
		{
			$tmpvar*=10;
			$tmpvar+=$c[$tc];	
		}
		$sumhash{$tmpvar}=1;
		
		$count++;
		$j--;
		
	}
	elsif($tmpsum < $sum)
	{
#print "\nEntered: $tmpsum < $sum";
		$j--;
	}
	else
	{		
#print "\nEntered: $tmpsum > $sum";
		$i++;
		$j=$k-1;
		$tmpsum=$c[$i];	
	}
}
$k--;
}

print "\nAfter first loop; count=$count, k=$k";

#Fixing the end and floating the start.
$k=@c;
while($k>=0)
{
$j=$k-1;
$i=0;
$tmpsum=$c[$j];
while($i<$j)
{
	$tmpsum+=$c[$i];
print "\nk=$k,i=$i,j=$j,c[i]=$c[$i],c[j]=$c[$j],tmpsum=$tmpsum,count=$count";
	if($tmpsum == $sum)
	{
		$tmpvar=$c[$j];
		for($tc=$i;$tc>=0;$tc--)
		{
			$tmpvar*=10;
			$tmpvar+=$c[$tc];	
		}
		$sumhash{$tmpvar}=1;
		
		$count++;
		$i++;
	}
	elsif($tmpsum < $sum)
	{
		$i++;		
	}
	else
	{
		$j--;
		$i=0;
		$tmpsum=$c[$j];		
	}
}
$k--;
}

$count = keys %sumhash;
print "\nCount: $count. They are;(";
while(($key,$val)=each(%sumhash))
{
	print "$key ";
}
print ")\n\n";
exit 0;

#p(aub) = p(a) +p(b) - p(anb)