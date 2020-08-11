import threading
import time
import datetime
import feeder_mechanism as feeder

class Schedule_Manager:
	def __init__(self):
		self.schedules = list()
		self.completed_schedules = list()
		self.incompleted_schedules = list()
		self.running = False
		self.manager_thread = None
		# self.schedules = get_schedules_from_file(Today's date)

	def assign_schedule(self, schedule_string):
		schedule_timestamp = time.mktime(datetime.datetime.strptime(schedule_string, "%Y-%m-%d %H:%M:%S"))

		self.schedules.append(schedule_timestamp)
		self.incompleted_schedules.append(schedule_timestamp)

		self.store_schedules(schedule_string, schedule_timestamp)

	def store_schedules(self, schedule_string):
		pass

	def start(self):
		self.running = True

		if self.manager_thread is None:
			self.manager_thread = threading.Thread(target = self.monitor_schedule)
			self.manager_thread.start()
		else:
			# TODO

	def stop(self):
		self.running = False

		if self.manager_thread is not None:
			self.manager_thread.stop()
		else:
			# TODO

	def monitor_schedule(self, sleep_time = 60):
		while self.running:
			current_time = time.time()
			for timestamp in self.incompleted_schedules:
				if current_time >= timestamp:
					#feeder.activate()
					self.completed_schedules.append(timestamp)
					self.incompleted_schedules.remove(timestamp)

			time.sleep(sleep_time)