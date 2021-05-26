def main():
	p_Map = []
	Phy_fra_table = []
	vir_page_table = []

	size = int(input("Enter tho no. of words "))
	w_size = int(input("Enter word size: "))

	vir_page_table = set_virtual_page_table(
		vir_page_table=vir_page_table, size=size, word_size=w_size)
	p_Map = set_page_mapping(p_Map=p_Map, size=size)

	sorted_mapping = list(p_Map)
	sorted_mapping.sort()

	Phy_fra_table = get_physical_frame_table(
		p_Map, Phy_fra_table, vir_page_table, sorted_mapping[-1], w_size)

	print("Virtual Page Table[] : {}".format(vir_page_table))
	print("Page Mapping[] : {}".format(p_Map))
	print("Physical Frame Table[] : {}".format(Phy_fra_table))


def set_virtual_page_table(vir_page_table=[], size=0, word_size=0):
	temp = []
	for offset in range(0, size):
		for elem in range(0, word_size):
			temp.append(input("Enter value for offset #{}[{}]: ".format(offset, elem)))
		vir_page_table.append(temp)
		temp = []
	return vir_page_table


def set_page_mapping(p_Map=[], size=0):
	for offset in range(0, size):
		p_Map.append(
			int(input("Enter page number for offset #{}: ".format(offset))))
	return p_Map


def get_physical_frame_table(p_Map=[], Phy_fra_table=[], vir_page_table=[], upperbound=0, w_size=0):
	for f_num in range(0, upperbound + 1):
		Phy_fra_table.append([
			f_num * w_size,
			vir_page_table[p_Map.index(
				f_num)] if f_num in p_Map else None
		])
	return Phy_fra_table


if __name__ == '__main__':
	import os
	os.system('clear')
	main()
