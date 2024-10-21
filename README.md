# Group Password Manager for Shared Credentials

## Repository Structure

### Folders

* src    - Source code
* tests  - Test code
* sdl    - Software development library
* libs   - Software dependencies (libraries)
* .gitea - Issue and Pull Request Templates

### Files

* .gitattributes - Configuration of file type settings
* .gitignore     - List of files to ignore on commits

Other top-level files are described below.

## Software Peer Review Process

When a pull request (PR) is created the team member creating the PR will complete the pull request template. This template ensures that every PR contains all the information needed to support an effective and efficient peer review.

Every PR must be reviewed and approved by at least two other team members. The reviewers must verify the PR's source code meets the project's standards. To streamline the review process, reviewers shall use the included [pull request review template](pull_request_review_template.md) document.

## Code Style Verification

The included `.clang-format` file is the configuration file for the `clang-format` tool. This tool may be used to enforce a C++ source code style. The file included here is based on the Mozilla coding style for C++. For instructions on how you may automatically check and/or format your source code, see the [code style](code_style.md) document.

