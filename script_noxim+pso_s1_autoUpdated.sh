#Doan script nay se chay chuong trinh voi ket qua mau da san co lay tu cho em Huong va thay Trien de dua vao noxim mo phong!
d1=`date +%d%m%y`
oF1=dataout_s1_bf_date${d1}
d2=`date +%d%m%y`
oF2=dataout_s1_af_date${d2}
rm ${oF2} ${oF1}
#dich chuong trinh sinh file .cg
g++ gen_CG_file.cpp -o PSO+NoC
./PSO+NoC #file nay da chay duoc ok nhung chua lien ket duoc do boi chua tao duoc dau ra cua fule la data_sc_bf.cg va dat_sc_af.bg
#ap dung cho loi ra truoc khi thuc hien pso
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.010 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.015 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.020 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.025 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.030 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.035 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.040 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.045 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.050 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.055 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.060 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.065 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.070 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.075 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.080 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.085 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.090 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.095 poisson >> ${oF1};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_bf.cg -pir 0.10 poisson >> ${oF1};
#ap dung cho loi ra sau khi thuc hien pso
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.010 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.015 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.020 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.025 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.030 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.035 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.040 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.045 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.050 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.055 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.060 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.065 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.070 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.075 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.080 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.085 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.090 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.095 poisson >> ${oF2};
./noxim -dimx 8 -dimy 8 -routing XY -traffic table core_graph_af.cg -pir 0.100 poisson >> ${oF2};



#////////////////////

#d2='dataout_s1_af_date+%d%m%y'

#creteate gnuplot files to draw

#GAD output
echo "#GAD: Global Average Delay scripts
set term postscript eps color blacktext \"GAD\" 24
set out \"GAD_s1_date$(date +%d%m%y).eps\"
set title \"Global Average Delay\"
set xlabel \"Packet Injection Rate (PIR)\"
set xrange [0:10]
#set autoscale
set ylabel \"Latency (Cycles)\"
set key bottom right
plot \"dataout_s1_bf_date$(date +%d%m%y)\" using 3 title \"before PSO\" lw 16 lc rgb \"blue\", \\
\"dataout_s1_af_date$(date +%d%m%y)\" using 3 title \"after PSO\" lw 10 lc rgb \"red\"
set output
quit
" > gnuplot_sh_s1_GAD

gnuplot gnuplot_sh_s1_GAD

#T output

echo "#T: Throughput
set term postscript eps color blacktext \"GAD\" 24
set out \"T_s1_date$(date +%d%m%y).eps\"
set title \"Throughput\"
set xlabel \"Packet Injection Rate (PIR)\"
set xrange [0:10]
set ylabel \"Throughpt (Cycles)\"
set key bottom right
plot \"dataout_s1_bf_date$(date +%d%m%y)\" using 5 title \"before PSO\" lw 16 lc rgb \"blue\", \\
\"dataout_s1_af_date$(date +%d%m%y)\" using 5 title \"after PSO\" lw 10 lc rgb \"red\"
set output
quit
" > gnuplot_sh_s1_T

gnuplot gnuplot_sh_s1_T



#TP output

echo "#TP: Total Power energy
set term postscript eps color blacktext \"GAD\" 24
set out \"TP_s1_date$(date +%d%m%y).eps\"
set title \"Total Power Energy\"
set xlabel \"Packet Injection Rate (PIR)\"
set xrange [0:10]
set ylabel \"Total Power (J)\"
set key bottom right
plot \"dataout_s1_bf_date$(date +%d%m%y)\" using 7 title \"before PSO\" lw 16 lc rgb \"blue\", \\
\"dataout_s1_af_date$(date +%d%m%y)\" using 7 title \"after PSO\" lw 10 lc rgb \"red\"
set output
quit
" > gnuplot_sh_s1_TP

gnuplot gnuplot_sh_s1_TP

#epstopdf *.eps
