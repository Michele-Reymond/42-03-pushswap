# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreymond <mreymond@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 19:48:18 by mreymond          #+#    #+#              #
#    Updated: 2022/02/22 18:39:41 by mreymond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= src/push_swap.c \
			src/ps_errors.c \
			src/ps_linked_list.c \
			src/ps_push.c \
			src/ps_rotate.c \
			src/ps_swap.c \
			src/ps_utils.c \
			src/ps_algo_bubble.c \
			src/ps_algo_pivot.c \
			src/ps_algo_pivot2.c \
			src/ps_algo_pivot_3.c

OBJS		= $(SRCS:.c=.o)

LBFT_PATH 	= ./src/libft/

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= push_swap
RM			= rm -f


all:		$(NAME)

$(NAME):	$(OBJS)
			@$(MAKE) --silent -C $(LBFT_PATH)
			$(CC) $(CFLAGS) $(OBJS) -L $(LBFT_PATH) -lft -o $(NAME)

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

run:		
			./$(NAME) "318 -181 25 -15 -160 211 -111 297 -234 119 375 -59 -110 -116 -237 -189 -225 404 -154 -156 -128 -153 220 494 173 -29 219 79 -235 -8 188 -174 107 -32 92 -149 -44 4 -103 414 182 271 477 161 11 41 322 -4 329 40 208 411 -177 268 -221 29 154 -92 59 473 276 176 64 104 291 216 202 437 366 -226 22 178 6 50 -127 54 379 382 -100 285 -104 441 341 -250 121 -193 -144 235 209 127 336 10 168 5 45 -36 -52 -23 381 262 435 -121 93 353 39 -190 96 172 222 183 213 -10 134 367 122 -106 377 -216 -246 73 -80 32 190 151 113 474 428 316 -180 -129 306 131 232 221 -232 487 430 -240 279 -201 -70 -98 420 483 344 340 -182 298 195 83 385 321 153 89 251 -152 149 84 429 333 299 287 -67 -20 -185 450 227 -55 347 -45 -125 -176 359 -188 126 -22 225 206 -217 -66 275 415 -9 314 62 229 -223 266 141 -79 478 80 350 308 68 423 337 -170 -142 440 284 51 403 -155 499 184 88 186 -231 -84 -60 163 490 456 498 -42 269 -229 452 140 95 133 215 -208 249 -34 -167 482 -196 311 56 -122 26 -12 401 181 -197 295 259 288 180 111 -35 110 438 175 390 60 312 7 205 125 57 124 129 65 244 203 171 444 373 -17 49 -238 38 281 255 -5 263 -88 130 -46 -95 -162 467 76 -38 331 19 115 394 290 476 378 164 196 -81 320 462 397 146 157 442 273 240 363 8 199 294 -65 -49 277 485 -26 -118 201 -165 -21 9 489 70 459 53 148 -27 105 100 241 -179 343 -134 261 114 48 75 495 446 356 -178 13 -126 -130 453 370 -94 98 239 348 486 189 -203 274 14 -124 -39 352 391 460 -117 387 36 15 106 -205 -207 -211 326 147 101 37 -102 200 315 417 -43 -200 81 -83 -63 -90 313 -132 170 -58 383 419 217 -112 432 393 -41 223 -138 280 236 248 465 408 -148 246 -173 -184 -224 410 293 399 -25 252 -11 301 -61 -3 150 138 177 28 143 -169 31 -76 398 256 472 475 416 -115 103 -187 -145 71 492 94 310 -109 1 305 -78 -139 23 -171 158 46 -198 468 -75 392 451 116 -212 34 412 212 -146 -163 -71 -91 193 364 443 433 -204 -133 142 -48 12 159 283 458 169 69 52 -141 174 -228 -37 -183 136 230 351 -53 257 3 72 74 78 -97 224 418 431 43 204 355 61 426 -215 -202 -24 448 -62 357 207 -123 -54 286 137 395 218 132 -93 90"

test:
			ARG="318 -181 25 -15 -160 211 -111 297 -234 119 375 -59 -110 -116 -237 -189 -225 404 -154 -156 -128 -153 220 494 173 -29 219 79 -235 -8 188 -174 107 -32 92 -149 -44 4 -103 414 182 271 477 161 11 41 322 -4 329 40 208 411 -177 268 -221 29 154 -92 59 473 276 176 64 104 291 216 202 437 366 -226 22 178 6 50 -127 54 379 382 -100 285 -104 441 341 -250 121 -193 -144 235 209 127 336 10 168 5 45 -36 -52 -23 381 262 435 -121 93 353 39 -190 96 172 222 183 213 -10 134 367 122 -106 377 -216 -246 73 -80 32 190 151 113 474 428 316 -180 -129 306 131 232 221 -232 487 430 -240 279 -201 -70 -98 420 483 344 340 -182 298 195 83 385 321 153 89 251 -152 149 84 429 333 299 287 -67 -20 -185 450 227 -55 347 -45 -125 -176 359 -188 126 -22 225 206 -217 -66 275 415 -9 314 62 229 -223 266 141 -79 478 80 350 308 68 423 337 -170 -142 440 284 51 403 -155 499 184 88 186 -231 -84 -60 163 490 456 498 -42 269 -229 452 140 95 133 215 -208 249 -34 -167 482 -196 311 56 -122 26 -12 401 181 -197 295 259 288 180 111 -35 110 438 175 390 60 312 7 205 125 57 124 129 65 244 203 171 444 373 -17 49 -238 38 281 255 -5 263 -88 130 -46 -95 -162 467 76 -38 331 19 115 394 290 476 378 164 196 -81 320 462 397 146 157 442 273 240 363 8 199 294 -65 -49 277 485 -26 -118 201 -165 -21 9 489 70 459 53 148 -27 105 100 241 -179 343 -134 261 114 48 75 495 446 356 -178 13 -126 -130 453 370 -94 98 239 348 486 189 -203 274 14 -124 -39 352 391 460 -117 387 36 15 106 -205 -207 -211 326 147 101 37 -102 200 315 417 -43 -200 81 -83 -63 -90 313 -132 170 -58 383 419 217 -112 432 393 -41 223 -138 280 236 248 465 408 -148 246 -173 -184 -224 410 293 399 -25 252 -11 301 -61 -3 150 138 177 28 143 -169 31 -76 398 256 472 475 416 -115 103 -187 -145 71 492 94 310 -109 1 305 -78 -139 23 -171 158 46 -198 468 -75 392 451 116 -212 34 412 212 -146 -163 -71 -91 193 364 443 433 -204 -133 142 -48 12 159 283 458 169 69 52 -141 174 -228 -37 -183 136 230 351 -53 257 3 72 74 78 -97 224 418 431 43 204 355 61 426 -215 -202 -24 448 -62 357 207 -123 -54 286 137 395 218 132 -93 90"; ./$(NAME) $$ARG | wc -l
			ARG="318 -181 25 -15 -160 211 -111 297 -234 119 375 -59 -110 -116 -237 -189 -225 404 -154 -156 -128 -153 220 494 173 -29 219 79 -235 -8 188 -174 107 -32 92 -149 -44 4 -103 414 182 271 477 161 11 41 322 -4 329 40 208 411 -177 268 -221 29 154 -92 59 473 276 176 64 104 291 216 202 437 366 -226 22 178 6 50 -127 54 379 382 -100 285 -104 441 341 -250 121 -193 -144 235 209 127 336 10 168 5 45 -36 -52 -23 381 262 435 -121 93 353 39 -190 96 172 222 183 213 -10 134 367 122 -106 377 -216 -246 73 -80 32 190 151 113 474 428 316 -180 -129 306 131 232 221 -232 487 430 -240 279 -201 -70 -98 420 483 344 340 -182 298 195 83 385 321 153 89 251 -152 149 84 429 333 299 287 -67 -20 -185 450 227 -55 347 -45 -125 -176 359 -188 126 -22 225 206 -217 -66 275 415 -9 314 62 229 -223 266 141 -79 478 80 350 308 68 423 337 -170 -142 440 284 51 403 -155 499 184 88 186 -231 -84 -60 163 490 456 498 -42 269 -229 452 140 95 133 215 -208 249 -34 -167 482 -196 311 56 -122 26 -12 401 181 -197 295 259 288 180 111 -35 110 438 175 390 60 312 7 205 125 57 124 129 65 244 203 171 444 373 -17 49 -238 38 281 255 -5 263 -88 130 -46 -95 -162 467 76 -38 331 19 115 394 290 476 378 164 196 -81 320 462 397 146 157 442 273 240 363 8 199 294 -65 -49 277 485 -26 -118 201 -165 -21 9 489 70 459 53 148 -27 105 100 241 -179 343 -134 261 114 48 75 495 446 356 -178 13 -126 -130 453 370 -94 98 239 348 486 189 -203 274 14 -124 -39 352 391 460 -117 387 36 15 106 -205 -207 -211 326 147 101 37 -102 200 315 417 -43 -200 81 -83 -63 -90 313 -132 170 -58 383 419 217 -112 432 393 -41 223 -138 280 236 248 465 408 -148 246 -173 -184 -224 410 293 399 -25 252 -11 301 -61 -3 150 138 177 28 143 -169 31 -76 398 256 472 475 416 -115 103 -187 -145 71 492 94 310 -109 1 305 -78 -139 23 -171 158 46 -198 468 -75 392 451 116 -212 34 412 212 -146 -163 -71 -91 193 364 443 433 -204 -133 142 -48 12 159 283 458 169 69 52 -141 174 -228 -37 -183 136 230 351 -53 257 3 72 74 78 -97 224 418 431 43 204 355 61 426 -215 -202 -24 448 -62 357 207 -123 -54 286 137 395 218 132 -93 90"; ./$(NAME) $$ARG | ./checker_Mac $$ARG

clean:
			$(RM) $(OBJS)
			@$(MAKE) -C $(LBFT_PATH) clean

fclean:		clean
			$(RM) $(NAME)
			@$(MAKE) -C $(LBFT_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re run test visu