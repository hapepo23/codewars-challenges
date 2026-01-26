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
	count_codepoints \
	counting_change_combinations \
	decode_morse \
	decode_roman \
	determinant \
	directions_reduction \
	divide_number_strings \
	escape_the_maze \
	eval_math_expression \
	evaporator \
	find_date \
	find_the_odd_int \
	format_duration \
	get_count \
	get_the_vowels \
	high_and_low \
	human_readable_time \
	integer_sqrt \
	irreducible_sum_of_rationals \
	is_anagram \
	is_ordered \
	is_valid_ip \
	is_valid_ISBN_10 \
	land_perimeter \
	large_factorials \
	letters_to_numbers \
	longest \
	make_spiral \
	move_zeros \
	multply_number_strings \
	not_very_secure \
	number_proper_fractions \
	ocr \
	order_words \
	parseint-reloaded \
	prime_factor_decomposition \
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
	strings_mix \
	sum_number_strings \
	sum_of_intervals \
	ten_minutes_walk

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
