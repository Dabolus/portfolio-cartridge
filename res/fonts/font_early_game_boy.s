; font_early_game_boy.s
; Text font
; Generated using commodore.zone Game Boy font generator
;

  .module 	font_early_game_boy
  .area	_HOME

_font_early_game_boy::
;   .byte	1+4		; 128 character encoding
;   .byte	50		; Tiles required

;   .byte	00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00
;   .byte	00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00
;   .byte	00,01,02,00,00,00,00,03,04,05,00,00,06,07,08,00
;   .byte	09,10,11,12,13,14,15,16,17,18,19,20,00,00,00,21
;   .byte	49,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36
;   .byte	37,38,39,40,41,42,43,44,45,46,47,00,48,00,00,00
;   .byte	00,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36
;   .byte	37,38,39,40,41,42,43,44,45,46,47,00,00,00,00,00

; Default character: space
  .db	0
        .db    0b00000000 
        .db    0b00000000 
        .db    0b00000000 
        .db    0b00000000 
        .db    0b00000000 
        .db    0b00000000 
        .db    0b00000000 
; Character: !
        .db    0b00000000 ;         
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00000000 ;         
        .db    0b00011000 ;    ██   
        .db    0b00000000 ;         
; Character: "
        .db    0b01101100 ;  ██ ██  
        .db    0b01101100 ;  ██ ██  
        .db    0b00100100 ;   █  █  
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00000000 ;         
; Character: '
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00001000 ;     █   
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00000000 ;         
; Character: (
        .db    0b00001100 ;     ██  
        .db    0b00011000 ;    ██   
        .db    0b00110000 ;   ██    
        .db    0b00110000 ;   ██    
        .db    0b00110000 ;   ██    
        .db    0b00011000 ;    ██   
        .db    0b00001100 ;     ██  
        .db    0b00000000 ;         
; Character: )
        .db    0b00011000 ;    ██   
        .db    0b00001100 ;     ██  
        .db    0b00000110 ;      ██ 
        .db    0b00000110 ;      ██ 
        .db    0b00000110 ;      ██ 
        .db    0b00001100 ;     ██  
        .db    0b00011000 ;    ██   
        .db    0b00000000 ;         
; Character: ,
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00001000 ;     █   
        .db    0b00010000 ;    █    
; Character: -
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00111100 ;   ████  
        .db    0b00111100 ;   ████  
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00000000 ;         
; Character: .
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00000000 ;         
; Character: 0
        .db    0b00000000 ;         
        .db    0b00111100 ;   ████  
        .db    0b01100110 ;  ██  ██ 
        .db    0b01100110 ;  ██  ██ 
        .db    0b01100110 ;  ██  ██ 
        .db    0b01100110 ;  ██  ██ 
        .db    0b00111100 ;   ████  
        .db    0b00000000 ;         
; Character: 1
        .db    0b00000000 ;         
        .db    0b00011000 ;    ██   
        .db    0b00111000 ;   ███   
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00111100 ;   ████  
        .db    0b00000000 ;         
; Character: 2
        .db    0b00000000 ;         
        .db    0b00111100 ;   ████  
        .db    0b01001110 ;  █  ███ 
        .db    0b00001110 ;     ███ 
        .db    0b00111100 ;   ████  
        .db    0b01110000 ;  ███    
        .db    0b01111110 ;  ██████ 
        .db    0b00000000 ;         
; Character: 3
        .db    0b00000000 ;         
        .db    0b01111100 ;  █████  
        .db    0b00001110 ;     ███ 
        .db    0b00111100 ;   ████  
        .db    0b00001110 ;     ███ 
        .db    0b00001110 ;     ███ 
        .db    0b01111100 ;  █████  
        .db    0b00000000 ;         
; Character: 4
        .db    0b00000000 ;         
        .db    0b00111100 ;   ████  
        .db    0b01101100 ;  ██ ██  
        .db    0b01001100 ;  █  ██  
        .db    0b01001100 ;  █  ██  
        .db    0b01111110 ;  ██████ 
        .db    0b00001100 ;     ██  
        .db    0b00000000 ;         
; Character: 5
        .db    0b00000000 ;         
        .db    0b01111100 ;  █████  
        .db    0b01100000 ;  ██     
        .db    0b01111100 ;  █████  
        .db    0b00001110 ;     ███ 
        .db    0b01001110 ;  █  ███ 
        .db    0b00111100 ;   ████  
        .db    0b00000000 ;         
; Character: 6
        .db    0b00000000 ;         
        .db    0b00111100 ;   ████  
        .db    0b01100000 ;  ██     
        .db    0b01111100 ;  █████  
        .db    0b01100110 ;  ██  ██ 
        .db    0b01100110 ;  ██  ██ 
        .db    0b00111100 ;   ████  
        .db    0b00000000 ;         
; Character: 7
        .db    0b00000000 ;         
        .db    0b01111110 ;  ██████ 
        .db    0b00000110 ;      ██ 
        .db    0b00001100 ;     ██  
        .db    0b00011000 ;    ██   
        .db    0b00111000 ;   ███   
        .db    0b00111000 ;   ███   
        .db    0b00000000 ;         
; Character: 8
        .db    0b00000000 ;         
        .db    0b00111100 ;   ████  
        .db    0b01001110 ;  █  ███ 
        .db    0b00111100 ;   ████  
        .db    0b01001110 ;  █  ███ 
        .db    0b01001110 ;  █  ███ 
        .db    0b00111100 ;   ████  
        .db    0b00000000 ;         
; Character: 9
        .db    0b00000000 ;         
        .db    0b00111100 ;   ████  
        .db    0b01001110 ;  █  ███ 
        .db    0b01001110 ;  █  ███ 
        .db    0b00111110 ;   █████ 
        .db    0b00001110 ;     ███ 
        .db    0b00111100 ;   ████  
        .db    0b00000000 ;         
; Character: :
        .db    0b00000000 ;         
        .db    0b00000000 ;         
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00000000 ;         
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00000000 ;         
; Character: ;
        .db    0b00000000 ;         
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00000000 ;         
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00001000 ;     █   
        .db    0b00010000 ;    █    
; Character: ?
        .db    0b01111000 ;  ████   
        .db    0b00011100 ;    ███  
        .db    0b00011100 ;    ███  
        .db    0b00111000 ;   ███   
        .db    0b00110000 ;   ██    
        .db    0b00000000 ;         
        .db    0b00110000 ;   ██    
        .db    0b00000000 ;         
; Character: A
        .db    0b00000000 ;         
        .db    0b00111100 ;   ████  
        .db    0b01001110 ;  █  ███ 
        .db    0b01001110 ;  █  ███ 
        .db    0b01111110 ;  ██████ 
        .db    0b01001110 ;  █  ███ 
        .db    0b01001110 ;  █  ███ 
        .db    0b00000000 ;         
; Character: B
        .db    0b00000000 ;         
        .db    0b01111100 ;  █████  
        .db    0b01100110 ;  ██  ██ 
        .db    0b01111100 ;  █████  
        .db    0b01100110 ;  ██  ██ 
        .db    0b01100110 ;  ██  ██ 
        .db    0b01111100 ;  █████  
        .db    0b00000000 ;         
; Character: C
        .db    0b00000000 ;         
        .db    0b00111100 ;   ████  
        .db    0b01100110 ;  ██  ██ 
        .db    0b01100000 ;  ██     
        .db    0b01100000 ;  ██     
        .db    0b01100110 ;  ██  ██ 
        .db    0b00111100 ;   ████  
        .db    0b00000000 ;         
; Character: D
        .db    0b00000000 ;         
        .db    0b01111100 ;  █████  
        .db    0b01001110 ;  █  ███ 
        .db    0b01001110 ;  █  ███ 
        .db    0b01001110 ;  █  ███ 
        .db    0b01001110 ;  █  ███ 
        .db    0b01111100 ;  █████  
        .db    0b00000000 ;         
; Character: E
        .db    0b00000000 ;         
        .db    0b01111110 ;  ██████ 
        .db    0b01100000 ;  ██     
        .db    0b01111100 ;  █████  
        .db    0b01100000 ;  ██     
        .db    0b01100000 ;  ██     
        .db    0b01111110 ;  ██████ 
        .db    0b00000000 ;         
; Character: F
        .db    0b00000000 ;         
        .db    0b01111110 ;  ██████ 
        .db    0b01100000 ;  ██     
        .db    0b01100000 ;  ██     
        .db    0b01111100 ;  █████  
        .db    0b01100000 ;  ██     
        .db    0b01100000 ;  ██     
        .db    0b00000000 ;         
; Character: G
        .db    0b00000000 ;         
        .db    0b00111100 ;   ████  
        .db    0b01100110 ;  ██  ██ 
        .db    0b01100000 ;  ██     
        .db    0b01101110 ;  ██ ███ 
        .db    0b01100110 ;  ██  ██ 
        .db    0b00111110 ;   █████ 
        .db    0b00000000 ;         
; Character: H
        .db    0b00000000 ;         
        .db    0b01000110 ;  █   ██ 
        .db    0b01000110 ;  █   ██ 
        .db    0b01111110 ;  ██████ 
        .db    0b01000110 ;  █   ██ 
        .db    0b01000110 ;  █   ██ 
        .db    0b01000110 ;  █   ██ 
        .db    0b00000000 ;         
; Character: I
        .db    0b00000000 ;         
        .db    0b00111100 ;   ████  
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00111100 ;   ████  
        .db    0b00000000 ;         
; Character: J
        .db    0b00000000 ;         
        .db    0b00011110 ;    ████ 
        .db    0b00001100 ;     ██  
        .db    0b00001100 ;     ██  
        .db    0b01101100 ;  ██ ██  
        .db    0b01101100 ;  ██ ██  
        .db    0b00111000 ;   ███   
        .db    0b00000000 ;         
; Character: K
        .db    0b00000000 ;         
        .db    0b01100110 ;  ██  ██ 
        .db    0b01101100 ;  ██ ██  
        .db    0b01111000 ;  ████   
        .db    0b01111000 ;  ████   
        .db    0b01101100 ;  ██ ██  
        .db    0b01100110 ;  ██  ██ 
        .db    0b00000000 ;         
; Character: L
        .db    0b00000000 ;         
        .db    0b01100000 ;  ██     
        .db    0b01100000 ;  ██     
        .db    0b01100000 ;  ██     
        .db    0b01100000 ;  ██     
        .db    0b01100000 ;  ██     
        .db    0b01111110 ;  ██████ 
        .db    0b00000000 ;         
; Character: M
        .db    0b00000000 ;         
        .db    0b01000110 ;  █   ██ 
        .db    0b01101110 ;  ██ ███ 
        .db    0b01111110 ;  ██████ 
        .db    0b01010110 ;  █ █ ██ 
        .db    0b01000110 ;  █   ██ 
        .db    0b01000110 ;  █   ██ 
        .db    0b00000000 ;         
; Character: N
        .db    0b00000000 ;         
        .db    0b01000110 ;  █   ██ 
        .db    0b01100110 ;  ██  ██ 
        .db    0b01110110 ;  ███ ██ 
        .db    0b01011110 ;  █ ████ 
        .db    0b01001110 ;  █  ███ 
        .db    0b01000110 ;  █   ██ 
        .db    0b00000000 ;         
; Character: O
        .db    0b00000000 ;         
        .db    0b00111100 ;   ████  
        .db    0b01100110 ;  ██  ██ 
        .db    0b01100110 ;  ██  ██ 
        .db    0b01100110 ;  ██  ██ 
        .db    0b01100110 ;  ██  ██ 
        .db    0b00111100 ;   ████  
        .db    0b00000000 ;         
; Character: P
        .db    0b00000000 ;         
        .db    0b01111100 ;  █████  
        .db    0b01100110 ;  ██  ██ 
        .db    0b01100110 ;  ██  ██ 
        .db    0b01111100 ;  █████  
        .db    0b01100000 ;  ██     
        .db    0b01100000 ;  ██     
        .db    0b00000000 ;         
; Character: Q
        .db    0b00000000 ;         
        .db    0b00111100 ;   ████  
        .db    0b01100010 ;  ██   █ 
        .db    0b01100010 ;  ██   █ 
        .db    0b01101010 ;  ██ █ █ 
        .db    0b01100100 ;  ██  █  
        .db    0b00111010 ;   ███ █ 
        .db    0b00000000 ;         
; Character: R
        .db    0b00000000 ;         
        .db    0b01111100 ;  █████  
        .db    0b01100110 ;  ██  ██ 
        .db    0b01100110 ;  ██  ██ 
        .db    0b01111100 ;  █████  
        .db    0b01101000 ;  ██ █   
        .db    0b01100110 ;  ██  ██ 
        .db    0b00000000 ;         
; Character: S
        .db    0b00000000 ;         
        .db    0b00111100 ;   ████  
        .db    0b01100000 ;  ██     
        .db    0b00111100 ;   ████  
        .db    0b00001110 ;     ███ 
        .db    0b01001110 ;  █  ███ 
        .db    0b00111100 ;   ████  
        .db    0b00000000 ;         
; Character: T
        .db    0b00000000 ;         
        .db    0b01111110 ;  ██████ 
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00000000 ;         
; Character: U
        .db    0b00000000 ;         
        .db    0b01000110 ;  █   ██ 
        .db    0b01000110 ;  █   ██ 
        .db    0b01000110 ;  █   ██ 
        .db    0b01000110 ;  █   ██ 
        .db    0b01001110 ;  █  ███ 
        .db    0b00111100 ;   ████  
        .db    0b00000000 ;         
; Character: V
        .db    0b00000000 ;         
        .db    0b01000110 ;  █   ██ 
        .db    0b01000110 ;  █   ██ 
        .db    0b01000110 ;  █   ██ 
        .db    0b01000110 ;  █   ██ 
        .db    0b00101100 ;   █ ██  
        .db    0b00011000 ;    ██   
        .db    0b00000000 ;         
; Character: W
        .db    0b00000000 ;         
        .db    0b01000110 ;  █   ██ 
        .db    0b01000110 ;  █   ██ 
        .db    0b01010110 ;  █ █ ██ 
        .db    0b01111110 ;  ██████ 
        .db    0b01101110 ;  ██ ███ 
        .db    0b01000110 ;  █   ██ 
        .db    0b00000000 ;         
; Character: X
        .db    0b00000000 ;         
        .db    0b01000110 ;  █   ██ 
        .db    0b00101100 ;   █ ██  
        .db    0b00011000 ;    ██   
        .db    0b00111000 ;   ███   
        .db    0b01100100 ;  ██  █  
        .db    0b01000010 ;  █    █ 
        .db    0b00000000 ;         
; Character: Y
        .db    0b00000000 ;         
        .db    0b01100110 ;  ██  ██ 
        .db    0b01100110 ;  ██  ██ 
        .db    0b00111100 ;   ████  
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00011000 ;    ██   
        .db    0b00000000 ;         
; Character: Z
        .db    0b00000000 ;         
        .db    0b01111110 ;  ██████ 
        .db    0b00001110 ;     ███ 
        .db    0b00011100 ;    ███  
        .db    0b00111000 ;   ███   
        .db    0b01110000 ;  ███    
        .db    0b01111110 ;  ██████ 
        .db    0b00000000 ;         
; Character: \
        .db    0b00000000 ;         
        .db    0b00100000 ;    █    
        .db    0b00010000 ;    █    
        .db    0b00010000 ;    █    
        .db    0b00001000 ;     █   
        .db    0b00001000 ;     █   
        .db    0b00000100 ;     █   
        .db    0b00000000 ;         
; Character: ©
        .db    0b00111000 ;   ███   
        .db    0b01000100 ;  █   █  
        .db    0b10111010 ; █ ███ █ 
        .db    0b10100010 ; █ █   █ 
        .db    0b10111010 ; █ ███ █ 
        .db    0b01000100 ;  █   █  
        .db    0b00111000 ;   ███   
        .db    0b00000000 ;         
