from router import Router
from schedule_manager import Schedule_Manager

class Endpoint_Main:
	def __init__(self):

		# read router info
		router_configs = self.get_router_info()

		self.router = Router(router_configs)
		self.schedule_manager = Schedule_Manager()

if __name__ == "__main__":
	main()