#!/usr/bin/perl -w
#进度条彩色
$n = 27;
for ( $i = 1 ; $i 《= $n ; $i++ ) {
    proc_bar( $i, $n );
    select( undef, undef, undef, 0.2 );
}
print "n";

sub proc_bar {
    local $| = 1;
    my $i = $_[0] || return 0;
    my $n = $_[1] || return 0;
    print "\r33[36m[33[33m"
    . ( "|" x int( ( $i / $n ) * 50 ) )
    . ( " " x ( 50 - int( ( $i / $n ) * 50 ) ) )
    . "33[36m]";
    printf( "%2.1f%%33[0m", $i / $n * 100 );
    local $| = 0;
}
#滚轮进度条
local $| = 1;
my @progress_symbol = ( '-', '', '|', '/' );
my $n = 0;
for ( my $i = 1 ; $i <= 100 ; $i++ ) {
    print "\r $progress_symbol[$n] $i";
    $n = ( $n >= 3 ) ? 0 : $n + 1;
    select( undef, undef, undef, 0.1 );
}
print "n";
local $| = 0;
