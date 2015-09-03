

from mininet.topo import Topo
from mininet.link import TCLink

class MyTopo( Topo ):
    

    def __init__( self ,x=10,y=5):
        

        # Initialize topology
        Topo.__init__( self) 
	hosts=[None] * (x+2)
	switches=[None] * (y+2)

        # Add x hosts and y switches
	for i in range(1,x+1):
		ip_mask = (i%2)+1;
		ip_add  = '10.'+str(ip_mask)+'.0.'+str(i)+'/16';
		print ip_add
		hosts[i] = self.addHost('host'+str(i),ip=ip_add);
		
		
	for i in range(1,y+1):
		switches[i] = self.addSwitch('s'+str(i));

        # Add switch-switch and host-switch links
	prev_switch=-1;
	ops1 = {'bw':1}
	ops2 = {'bw':2}
	for i in range(1,y+1):
		t= self.addLink(switches[i],hosts[2*i]);
		
		self.addLink(switches[i],hosts[2*i-1])
		if i!=1:
			self.addLink(switches[i],switches[i-1]);


topos = { 'mytopo': ( lambda: MyTopo() ) }
