dd if=/dev/zero of=lofs.img bs=1M count=50
losetup -fP logs.img
losetup -a
mkfs.ext4 ./lofs.img
mkdir lofsdisk
mount -o loop /dev/loop5 ./lofsdisk/
df -hP lofsdisk

