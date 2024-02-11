cmp	si,0x10     ; normalize ds:si
jb	end         ; address already normalized if si<16
mov	ax,si       ; 3 left-most hex-digits 
shr	ax,1        ; of si to di
shr	ax,1
shr	ax,1
shr	ax,1
mov	dx,ds			
add	dx,ax
mov	ds,dx
and	si,0xf      ; right-most hex-digit of si
end:
