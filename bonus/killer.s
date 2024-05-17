    .name    "ArAg0rn"
    .comment "La mort viens d'en haut"

	sti	r1, %:live, %1
    sti r1  %:survie %1
	fork	%:live
begin:	ld	%76, r1
    ld %29910 r2
    ld %21910 r3
    ld %139213 r4
    ld %72893 r5
    ld %92293 r6
    ld %123922 r7
    ld %89123, r8
    ld %123, r9
    ld %92, r10
    ld %1233, r11
    ld %7261, r14
    ld %981, r15
    ld %257, r16
	ld %0, r13
	sub	r4, r13, r11
    live %1
	fork    %:live
    live %1
    fork %:topille1
    zjmp %:topille2
live:	live	%666
	ld	%0, r1
	zjmp	%:live
survie: 
    live %666
	st	r8, 100
    add r7 r9 r9
    sti r9 r9 r4
	add	r6, r7, r7
	sti	r7, r7, r1
    add r2 r9 r2
    sti r2 r2 r8
	ld	%15, r4
	sub	r4, r13, r11
	ld	%0, r13
	zjmp	%:survie

topille1:
    live	%1
    fork %:survie
    live    %1
    fork %511
    live    %1
    lfork %1500
    live    %1
    lfork %2000
    live    %1
    ld    %0, r16
    zjmp    %2200

topille2:
    live	%1
    lfork %2750
    live    %1
    lfork %3500
    live    %1
    lfork %4250
    live    %1
    ld    %0, r16
    zjmp    %5000