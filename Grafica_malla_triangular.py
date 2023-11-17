import numpy as np
import matplotlib.pylab as plt
plt.rcParams['figure.dpi'] = 300

M=np.genfromtxt("Matriz_interconexion_tr.csv", delimiter=",")

p=0.4
pairs=M[:,0:2]
rand_nums=M[:,2]
xs=np.array([])
ys=np.array([])
N=int(np.sqrt(M[-1,0]+1))

bonds=np.array([])

def position(i,N):
    
    if(i%(2*N)<=N and i%(2*N)!=0):
        if(i%N==0):
            return [N-1+1/2,(np.sqrt(3)/2)*np.floor((i-1)/N)]
        else:
            return [(i%N)-1+1/2,(np.sqrt(3)/2)*np.floor((i-1)/N)]
    else:
        if(i%N==0):
            return [N-1,(np.sqrt(3)/2)*np.floor((i-1)/N)]
        else:
            return [(i%N)-1,(np.sqrt(3)/2)*np.floor((i-1)/N)]
    

for rand_num in rand_nums:
    if(rand_num<p):
        bonds=np.append(bonds,1)
    else:
        bonds=np.append(bonds,0)

for i in range(N):
    for j in range(N):
        if(i%2==0):
            xs=np.append(xs,j+1/2)
            ys=np.append(ys,np.sqrt(3)*i/2)
        else:
            xs=np.append(xs,j)
            ys=np.append(ys,np.sqrt(3)*i/2)



plt.figure()
plt.scatter(xs,ys, marker=".", s=0.5, c="black")
plt.axis("scaled")
plt.axis("off")


for i in range(len(bonds)):
    if(bonds[i]==1):
        pair=pairs[i,:]
        cor_in=position(pair[0],N)
        cor_end=position(pair[1],N)
        plt.plot([cor_in[0],cor_end[0]],[cor_in[1],cor_end[1]], c="r", lw="0.7")
        
plt.savefig("Primera_percolacion_triangular.png")         
        
       

