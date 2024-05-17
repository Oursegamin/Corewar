    .name    "Bunker"
    .comment "STOP"

tank:   live %666 
ld 9 r4
ld 900 r5
sti r4 r5 %0
sub r5 r10 r5
ld %0 r12
zjmp %:tank