from digi.xbee.devices import XBeeDevice, RemoteXbeeDevice

class Router:
	def __init__(self, node_id, router_port, baud_rate):
		self.node_id = node_id
		self.router_port = router_port
		self.baud_rate = baud_rate

		self.device = XBeeDevice(self.port, self.baud_rate)

	def receive_message(self, remote_node_id):
		xbee_message = None
		try:
			self.device.open()

			remote_device = RemoteXbeeDevice(self.device, Xbee64BitAddress.from_hex_strin(remote_node_id))
			xbee_message = self.device.read_data(remote_device)
		
		finally:
			if self.device is not None and self.device.is_open():
				device.close()
				return(xbee_message)

	def send_message(self, remote_node_id, xbee_message):
		try:
			self.device.open()

			xbee_network = device.get_network()
			remote_device = xbee_network.discover_device(remote_node_id)
			
			if remote_device is None:
				print("Could not find remote device")
				return False

			device.send_data(remote_device, xbee_message)

		
		finally:
			if self.device is not None and self.device.is_open():
				device.close()
				return True
