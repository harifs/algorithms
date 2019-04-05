#!\user\local\bin\perl -w

@arr=qw(a b c d);
@next=@arr;

$len=@arr;
$marker=$len;

while($marker)
{
	$m=1;	
	while($m<$len)
	{ 
		$n=$m;
		@printed=@next;
#print "\nSTART: n=$n; m=$m; len=$len; printed=@printed; stack=@stack";
		 while(($n--))
		 {
			$ch=pop(@printed);
			push(@stack,$ch);			
		 }
		 $n=$m;
		 while(($n--))
		 {
print "\nMIDDLE: n=$n; m=$m; len=$len; printed=@printed; stack=@stack";
		 	print "   @printed";
		 	while($ch=shift(@stack))
		 	{ 	
	 			print " $ch";	 				 			
	 	 	}	 	 	
	 	 	@printed=@next;
	 	 }
		 $m++;		 
#print "\nEND: n=$n; m=$m; len=$len; printed=@printed; stack=@stack";
	}	
	push(@next,shift(@next));
	$marker--;
	print "\n";
}


