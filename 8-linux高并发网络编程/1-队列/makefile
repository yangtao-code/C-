all:read write
read:read.c
	gcc $< -o $@
write:write.c
	gcc $< -o $@

cp:
	cp ~/code/1-* /mnt/hgfs/share -r

clean:
	rm read write
