#!/usr/bin/perl

print "Enter the 10-digit phone number:";
$number=<>;
chomp($number);
@num=split(//,$number);

my %phonepad = ();
%phonepad=(2=>abc,3=>def,4=>ghi,5=>jkl,6=>mno,7=>pqrs,8=>tuv,9=>wxyz);

while (($key,$value)=each(%phonepad))
{
  print "$key => $value\n";
}

my $i=0;
foreach $digit (@num)
{
  @letters=split(//,$phonepad{$digit});
  my $j=0;
  foreach $ltr (@letters)
  {
    #print "\n2nd DEBUG: i=$i ; j=$j ; ltr => $ltr\n";
    my $count=0;
    foreach $inner_dig (@num)
    {
#        print "\n3rd DEBUG: ltr=$ltr ; i=$i ; j=$j ; count=$count ; phonepad{inner_dig} => $phonepad{$inner_dig}\n";
        if ($count eq 0)
        {  
          print substr($phonepad{$inner_dig},$i,1);
        }
        else 
        { 
          print substr($phonepad{$inner_dig},$j,1);
        }
        $count++;
    }
    print "\n";
    $j++;
  }
  $i++;
}
