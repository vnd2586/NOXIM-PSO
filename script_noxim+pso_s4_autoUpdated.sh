#doan script nay se chay mo phong cho kich ban 2: voi pir = 0.025
d1=`date +%d%m%y`
oF1=dataout_s4_bf_date${d1}
d2=`date +%d%m%y`
oF2=dataout_s4_af_date${d2}
rm ${oF2} ${oF1}


#Doan script nay se chay chuong trinh voi ket qua mau da san co lay tu cho em Huong va thay Trien de dua vao noxim mo phong!
#rm ${oF2} ${oF1}
#dich chuong trinh sinh file .cg
g++ gen_CG_file.cpp -o PSO+NoC
./PSO+NoC #file nay da chay duoc ok nhung chua lien ket duoc do boi chua tao duoc dau ra cua fule la data_sc_bf.cg va dat_sc_af.bg
#ap dung cho loi ra truoc khi thuc hien pso voi pir = 0.10
./noxim -dimx 8 -dimy 8 -size 2 2 -routing XY -traffic table core_graph_bf.cg  -pir 0.025 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -size 4 4 -routing XY -traffic table core_graph_bf.cg  -pir 0.025 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -size 8 8 -routing XY -traffic table core_graph_bf.cg  -pir 0.025 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -size 16 16 -routing XY -traffic table core_graph_bf.cg  -pir 0.025 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -size 32 32 -routing XY -traffic table core_graph_bf.cg  -pir 0.025 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -size 64 64 -routing XY -traffic table core_graph_bf.cg  -pir 0.025 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -size 128 128 -routing XY -traffic table core_graph_bf.cg  -pir 0.025 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -size 256 256 -routing XY -traffic table core_graph_bf.cg  -pir 0.025 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -size 512 512 -routing XY -traffic table core_graph_bf.cg  -pir 0.025 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -size 1024 1024 -routing XY -traffic table core_graph_bf.cg  -pir 0.025 poisson >> ${oF1};

#ap dung cho loi ra sau khi thuc hien pso


./noxim -dimx 8 -dimy 8 -size 2 2 -routing XY -traffic table core_graph_af.cg  -pir 0.025 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -size 4 4 -routing XY -traffic table core_graph_af.cg  -pir 0.025 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -size 8 8 -routing XY -traffic table core_graph_af.cg  -pir 0.025 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -size 16 16 -routing XY -traffic table core_graph_af.cg  -pir 0.025 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -size 32 32 -routing XY -traffic table core_graph_af.cg  -pir 0.025 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -size 64 64 -routing XY -traffic table core_graph_af.cg  -pir 0.025 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -size 128 128 -routing XY -traffic table core_graph_af.cg  -pir 0.025 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -size 256 256 -routing XY -traffic table core_graph_af.cg  -pir 0.025 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -size 512 512 -routing XY -traffic table core_graph_af.cg  -pir 0.025 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -size 1024 1024 -routing XY -traffic table core_graph_af.cg  -pir 0.025 poisson >> ${oF2};



#drawing 



#GAD output
echo "#GAD: Global Average Delay scripts
set term postscript eps color blacktext \"GAD\" 24
set out \"GAD_s4_date$(date +%d%m%y).eps\"
set title \"Global Average Delay\"
set xlabel \"Packet Size (Flits)\"
set xrange [0:10]
set ylabel \"Latency (Cycles)\"
set key bottom right
plot \"dataout_s4_bf_date$(date +%d%m%y)\" using 3 title \"before PSO\" lw 16 lc rgb \"blue\", \\
\"dataout_s4_af_date$(date +%d%m%y)\" using 3 title \"after PSO\" lw 10 lc rgb \"red\"
set output
quit
" > gnuplot_sh_s4_GAD

gnuplot gnuplot_sh_s4_GAD




#T output

echo "#T: Throughput
set term postscript eps color blacktext \"GAD\" 24
set out \"T_s4_date$(date +%d%m%y).eps\"
set title \"Throughput\"
set xlabel \"Packet Size (Flits)\"
set xrange [0:10]
set ylabel \"Throughpt (Cycles)\"
set key bottom right
plot \"dataout_s4_bf_date$(date +%d%m%y)\" using 5 title \"before PSO\" lw 16 lc rgb \"blue\", \\
\"dataout_s4_af_date$(date +%d%m%y)\" using 5 title \"after PSO\" lw 10 lc rgb \"red\"
set output
quit
" > gnuplot_sh_s4_T

gnuplot gnuplot_sh_s4_T




#TP output

echo "#TP: Total Power energy
set term postscript eps color blacktext \"GAD\" 24
set out \"TP_s4_date$(date +%d%m%y).eps\"
set title \"Total Power Energy\"
set xlabel \"Packet Size (Flits)\"
set xrange [0:10]
set ylabel \"Total Power (J)\"
set key bottom right
plot \"dataout_s4_bf_date$(date +%d%m%y)\" using 7 title \"before PSO\" lw 16 lc rgb \"blue\", \\
\"dataout_s4_af_date$(date +%d%m%y)\" using 7 title \"after PSO\" lw 10 lc rgb \"red\"
set output
quit
" > gnuplot_sh_s4_TP

gnuplot gnuplot_sh_s4_TP

#epstopdf *.eps

