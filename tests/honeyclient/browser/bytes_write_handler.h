// Copyright (c) 2014 The Honeycomb Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#ifndef HONEYCOMB_TESTS_HONEYCOMBCLIENT_BROWSER_BYTES_WRITE_HANDLER_H_
#define HONEYCOMB_TESTS_HONEYCOMBCLIENT_BROWSER_BYTES_WRITE_HANDLER_H_
#pragma once

#include "include/base/honey_lock.h"
#include "include/honey_stream.h"

namespace client {

class BytesWriteHandler : public HoneycombWriteHandler {
 public:
  explicit BytesWriteHandler(size_t grow);
  ~BytesWriteHandler();

  size_t Write(const void* ptr, size_t size, size_t n) override;
  int Seek(int64_t offset, int whence) override;
  int64_t Tell() override;
  int Flush() override;
  bool MayBlock() override { return false; }

  void* GetData() { return data_; }
  int64_t GetDataSize() { return offset_; }

 private:
  size_t Grow(size_t size);

  size_t grow_;
  void* data_;
  int64_t datasize_;
  int64_t offset_;

  base::Lock lock_;

  IMPLEMENT_REFCOUNTING(BytesWriteHandler);
  DISALLOW_COPY_AND_ASSIGN(BytesWriteHandler);
};

}  // namespace client

#endif  // HONEYCOMB_TESTS_HONEYCOMBCLIENT_BROWSER_BYTES_WRITE_HANDLER_H_
