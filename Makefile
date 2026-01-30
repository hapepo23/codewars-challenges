CC = gcc
CFLAGS = -std=c18 -Wall -Wextra -O0 -g
LDLIBS = -lm

TARGETS = \
	adding_big_numbers \
	alphabet_position \
	array_exchange \
	big_integer_modulo \
	blackjack_scorer \
	bonus_time \
	categorize_new_member \
	common_denominators \
	count_codepoints \
	counting_change_combinations \
	count_ip_addresses \
	decode_morse \
	decode_roman \
	determinant \
	directions_reduction \
	divide_number_strings \
	escape_the_maze \
	eval_math_expression \
	evaporator \
	factorial_decomposition \
	factorial_trailing_zeros \
	fibonacci_squares_perimeter \
	find_date \
	find_the_odd_int \
	format_duration \
	get_count \
	get_the_vowels \
	greed_is_good \
	hex_string_to_rgb \
	high_and_low \
	human_readable_time \
	integer_sqrt \
	int32_to_ipv4 \
	irreducible_sum_of_rationals \
	is_anagram \
	is_ordered \
	is_valid_ip \
	is_valid_ISBN_10 \
	land_perimeter \
	large_factorials \
	last_digit_of_large_number \
	letters_to_numbers \
	longest \
	make_spiral \
	maximum_subarray_sum \
	mean_square_error \
	move_zeros \
	multiples_of_3_or_5 \
	multply_number_strings \
	my_strtok \
	next_bigger_number \
	not_very_secure \
	number_proper_fractions \
	ocr \
	ordered_set \
	order_words \
	parseint-reloaded \
	prime_factor_decomposition \
	product_consecutive_fibnum \
	range_extraction \
	rational_arithmetic \
	rectangle_rotation \
	rgb_to_hex \
	roman_num_encoder \
	roman_num_helper \
	rot13 \
	rotate \
	run_length_encoding \
	scramble \
	skyscrapers_4x4_puzzle \
	skyscrapers_6x6_puzzle \
	skyscrapers_7x7_puzzle \
	snail_sort \
	sort_numbers \
	square_into_squares \
	strclr \
	string_incrementer \
	strings_mix \
	sum_number_strings \
	sum_of_intervals \
	ten_minutes_walk \
	weight_for_weight \
	who_likes_it \
	your_own_printf

.PHONY: all clean reformat run vrun

all: $(TARGETS)

%: %.c %_main.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f $(TARGETS)

reformat:
	clang-format --style=Chromium -i *.c

run:
	./`zenity --title="Execute Program" --height 600 --list --text="Choose Executable" --column=Executable $(TARGETS)`

vrun:
	valgrind --leak-check=full --show-error-list=yes ./`zenity --title="Valgrind Program" --height 600 --list --text="Choose Executable" --column=Executable $(TARGETS)`
