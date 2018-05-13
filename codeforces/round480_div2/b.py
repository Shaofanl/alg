from subprocess import Popen, PIPE, STDOUT


from subprocess import call

if __name__ == '__main__':
    for n in range(3, 91):
        for k in range(2*(n-2)+1):
			print(n, k)

			p = Popen(['./b.exe'], stdout=PIPE, stdin=PIPE, stderr=PIPE)
			stdout_data = p.communicate(input='{} {}'.format(n, k))[0]
			if (len(stdout_data) == 0):
				raise Exception
			print(stdout_data)