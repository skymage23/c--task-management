add_library(routing STATIC
   ${CMAKE_CURRENT_LIST_DIR}/mailbox.cpp
   ${CMAKE_CURRENT_LIST_DIR}/rootmailbox.cpp
   ${CMAKE_CURRENT_LIST_DIR}/broadcastmailbox.cpp
   ${CMAKE_CURRENT_LIST_DIR}/mailboxpackage.cpp
   ${CMAKE_CURRENT_LIST_DIR}/mailboxutilitypackage.cpp
   ${CMAKE_CURRENT_LIST_DIR}/mailboxletterpackage.cpp
)

target_include_directories (routing
   PUBLIC ${CMAKE_SOURCE_DIR}/include
)