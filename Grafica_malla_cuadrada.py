import numpy as np
import matplotlib.pylab as plt
plt.rcParams['figure.dpi'] = 300

pairs=np.genfromtxt("Matriz_interconexion_sq.csv", delimiter=",")
bonds=np.genfromtxt("Matriz_de_enlaces_sq.csv", delimiter=",")


xs=np.array([])
ys=np.array([])
N=int(np.sqrt(pairs[-1,0]+1))


def position(i,N):
    return [(i-1)%N,np.floor((i-1)/N)]
    

for i in range(N):
    for j in range(N):
       xs=np.append(xs,i)
       ys=np.append(ys,j)

plt.figure()


for j in range(len(bonds[0,:])):
    plt.scatter(xs,ys, marker=".", s=0.5, c="black")
    plt.axis("scaled")
    plt.axis("off")
    for i in range(len(bonds[:,0])-1):
        if(bonds[i+1,j]==1):
            print(bonds[i+1,j])
            pair=pairs[i,:]
            cor_in=position(pair[0],N)
            cor_end=position(pair[1],N)
            plt.plot([cor_in[0],cor_end[0]],[cor_in[1],cor_end[1]], c="r", lw="0.7")
    plt.savefig("Grafica_percolacion_sq_"+str(bonds[0,j])+".png")
    plt.cla()

