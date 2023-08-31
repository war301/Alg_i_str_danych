import numpy
# Specifyimage widthand height
w, h = 200, 200
# Specifyreal and imaginaryrangeof image
re_min, re_max= -2.0, 2.0
im_min, im_max= -2.0, 2.0
# Picka valuefor c
c = complex(0.0,0.65)
# Generateevenlyspacedvaluesoverreal and imaginaryranges
real_range= numpy.arange(re_min, re_max, (re_max-re_min) / w)
imag_range= numpy.arange(im_max, im_min, (im_min-im_max) / h)
# Open outputfile and writePGM headerinfo
fout= open('julia.pgm', 'w')
fout.write('P2\n# Julia Set image\n' + str(w) + ' ' + str(h) + '\n255\n')
# Generate pixel values and write to file
for im in imag_range:
    for re in real_range:
        z = complex(re, im)
        n = 250
        while abs(z) < 10 and n >= 5:
            z = z*z + c
            n -= 5
        # Write pixel to file
        fout.write(str(n) + ' ')
        # End of row
    fout.write('\n')
# Close file
fout.close()