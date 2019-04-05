#!\home\user\local\bin\perl

print "enter the string:";
$str=<> || die "Read failed. Reason <$!>";
chomp($str);
@char=split(//,$str);
$len=@char;

&printar(\@char,$len);
printarv(@char,$len);

sub printar
{
 ($ch,$len)=@_; 
 my @ar=@$ch;
 push(@ar,('d','e'));
 print "\n AR(ref)=@ar; len=$len";
 print "\n Char(ref)=@char; len=$len";
 
 $str=join('',@$ch);
 print "\nSTR=$str";
}

sub printarv (@ar,$len)
{
	my @ar=@char;
	push(@ar,'d');
	print "\n AR(val)=@ar; len=$len";
	print "\n Char(val)=@char; len=$len";
}

exit;